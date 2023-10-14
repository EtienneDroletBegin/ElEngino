#pragma once
#include "iAudio.h"
#include "SDL_mixer.h"
#include "map"

namespace engino {

	class AudioMixer : public IAudio
	{

	public:
		AudioMixer();
		virtual size_t LoadMusic(const char* filename) override;
		virtual size_t LoadSound(const std::string& filename) override;
		virtual void PlayMusic(size_t id, int loop) override;
		virtual void PlaySFX(size_t id, int loop) override;
		virtual void PauseMusic() override;
		virtual void StopMusic() override;
		virtual void ResumeMusic() override;
		virtual void SetVolume(int volume) override;
		virtual void SetVolume(size_t soundId, int volume) override;

	private:
		std::map<size_t, Mix_Music*> MusicMap;
		std::map<size_t, Mix_Chunk*> ChunkMap;
	};

}