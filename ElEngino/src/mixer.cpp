#include "mixer.h"
#include "SDL_Mixer.h"

engino::AudioMixer::AudioMixer()
{
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
}

size_t engino::AudioMixer::LoadMusic(std::string filename)
{
	const size_t _musId = std::hash<std::string>()(filename);
	if (MusicMap->count(_musId))
	{
		return _musId;
	}

	Mix_Music* _mus = Mix_LoadMUS(filename.c_str());
	if (_mus)
	{
		MusicMap->emplace(_musId, _mus);
		return _musId;
	}

	return 0;
}

size_t engino::AudioMixer::LoadSound(const std::string& filename)
{
	const size_t chunkId = std::hash<std::string>()(filename);
	if (ChunkMap->find(chunkId) != ChunkMap->end()) {
		return chunkId;
	}
	Mix_Chunk* _chunk = Mix_LoadWAV(filename.c_str());

	if (_chunk != NULL) {
		ChunkMap->emplace(chunkId, _chunk);
		return chunkId;
	}
	return -1;
}

void engino::AudioMixer::PlayMusic(std::string filename, int loop)
{
	size_t id = LoadMusic(filename);

	Mix_PlayMusic(MusicMap->at(id), loop);
}

void engino::AudioMixer::PlaySFX(size_t id, int loop)
{

	if (ChunkMap->count(id) > 0)
	{
		Mix_Chunk* sfx = ChunkMap->at(id);

		if (Mix_PlayChannel(-1, sfx, 0) != -1)
		{
			Mix_PlayChannel(-1, ChunkMap->at(id), loop);

		}
	}
}

void engino::AudioMixer::PauseMusic()
{
}

void engino::AudioMixer::StopMusic()
{
	
}

void engino::AudioMixer::ResumeMusic()
{
}

void engino::AudioMixer::SetVolume(int volume)
{
}

void engino::AudioMixer::SetVolume(size_t soundId, int volume)
{
}

void engino::AudioMixer::Destroy()
{
	for (auto music : *MusicMap)
	{
		Mix_FreeMusic(music.second);
	}

	for (auto Chunk : *ChunkMap)
	{
		Mix_FreeChunk(Chunk.second);
	}
	ChunkMap->clear();
	MusicMap->clear();
	delete MusicMap;
	delete ChunkMap;
	Mix_CloseAudio();
	Mix_Quit();
}
