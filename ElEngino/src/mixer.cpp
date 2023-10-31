#include "mixer.h"
#include "SDL_Mixer.h"

engino::AudioMixer::AudioMixer()
{
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
}

size_t engino::AudioMixer::LoadMusic(const char* filename)
{
	const size_t musicId = std::hash<std::string>()(filename);

	if (MusicMap.find(musicId) != MusicMap.end()) {
		return musicId;
	}
	Mix_Music* _music = Mix_LoadMUS(filename);

	if (_music != nullptr) {
		MusicMap[musicId] = _music;
		return musicId;
	}
}

size_t engino::AudioMixer::LoadSound(const std::string& filename)
{
	const size_t chunkId = std::hash<std::string>()(filename);
	if (ChunkMap.find(chunkId) != ChunkMap.end()) {
		return chunkId;
	}
	Mix_Chunk* _chunk = Mix_LoadWAV(filename.c_str());

	if (_chunk != NULL) {
		ChunkMap[chunkId] = _chunk;
		return chunkId;
	}
}

void engino::AudioMixer::PlayMusic(size_t id, int loop)
{
	Mix_PlayMusic(MusicMap[id], loop);
}

void engino::AudioMixer::PlaySFX(size_t id, int loop)
{

	if (ChunkMap.count(id) > 0)
	{
		Mix_Chunk* sfx = ChunkMap[id];

		if (Mix_PlayChannel(-1, sfx, 0) != -1)
		{
			Mix_PlayChannel(-1, ChunkMap[id], loop);

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
