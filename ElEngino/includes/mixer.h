#pragma once
#include "iAudio.h"
#include "map"

struct Mix_Chunk;
typedef struct _Mix_Music Mix_Music;

namespace engino {

	class AudioMixer : public IAudio
	{

	public:
		AudioMixer();
		~AudioMixer() = default;
		/// <summary>
		/// Loads a song to the system
		/// </summary>
		/// <param name="filename">the audio file to get</param>
		/// <returns>the Hash's ID</returns>
		virtual size_t LoadMusic(std::string filename) override;
		/// <summary>
		/// Loads a SFX into the System
		/// </summary>
		/// <param name="filename">the audio file to get</param>
		/// <returns></returns>
		virtual size_t LoadSound(const std::string& filename) override;
		/// <summary>
		/// plays one of the saved Files
		/// </summary>
		/// <param name="id">the hash's id for the file</param>
		/// <param name="loop">if it loops</param>
		virtual void PlayMusic(std::string filename, int loop) override;
		/// <summary>
		/// plays one of the saved SFXs
		/// </summary>
		/// <param name="id">the hash's id for the file</param>
		/// <param name="loop">if it loops</param>
		virtual void PlaySFX(size_t id, int loop) override;
		/// <summary>
		/// pause the currently playing music
		/// </summary>
		virtual void PauseMusic() override;
		/// <summary>
		/// stops the current track
		/// </summary>
		virtual void StopMusic() override;
		/// <summary>
		/// unpause the current track
		/// </summary>
		virtual void ResumeMusic() override;
		/// <summary>
		/// sets the volume for the current track
		/// </summary>
		/// <param name="volume">the volume</param>
		virtual void SetVolume(int volume) override;
		virtual void SetVolume(size_t soundId, int volume) override;
		/// <summary>
		/// destroys the pointers to avoid memory leaks
		/// </summary>
		virtual void Destroy() override;

	private:
		std::map<size_t, Mix_Music*> *MusicMap = new std::map<size_t, Mix_Music*>();
		std::map<size_t, Mix_Chunk*> *ChunkMap = new std::map<size_t, Mix_Chunk*>();
	};

}