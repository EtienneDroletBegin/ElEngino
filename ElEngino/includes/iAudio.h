#pragma once
#include <iostream>
#include <string>

namespace engino {
	class IAudio
	{
	public:
		/// <summary>
		/// Loads a song to the system
		/// </summary>
		/// <param name="filename">the audio file to get</param>
		/// <returns>the Hash's ID</returns>
		virtual size_t LoadMusic(std::string filename) = 0;
		/// <summary>
		/// Loads a SFX into the System
		/// </summary>
		/// <param name="filename">the audio file to get</param>
		/// <returns></returns>
		virtual size_t LoadSound(const std::string& filename) = 0;
		/// <summary>
		/// plays one of the saved Files
		/// </summary>
		/// <param name="id">the hash's id for the file</param>
		/// <param name="loop">if it loops</param>
		virtual void PlayMusic(std::string filename, int loop) = 0;
		/// <summary>
		/// plays one of the saved SFXs
		/// </summary>
		/// <param name="id">the hash's id for the file</param>
		/// <param name="loop">if it loops</param>
		virtual void PlaySFX(size_t id, int loop) = 0;
		/// <summary>
		/// pause the currently playing music
		/// </summary>
		virtual void PauseMusic() = 0;
		/// <summary>
		/// stops the current track
		/// </summary>
		virtual void StopMusic() = 0;
		/// <summary>
		/// unpauses the current track
		/// </summary>
		virtual void ResumeMusic() = 0;
		/// <summary>
		/// changes the playback volume
		/// </summary>
		/// <param name="volume">the level to set the volume</param>
		virtual void SetVolume(int volume) = 0;
		virtual void SetVolume(size_t soundId, int volume) = 0;
		/// <summary>
		/// destroys the pointers to avoid memory leaks
		/// </summary>
		virtual void Destroy() = 0;


	};

}
