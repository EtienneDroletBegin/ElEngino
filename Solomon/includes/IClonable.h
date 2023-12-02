#pragma once

namespace engino {
	/// <summary>
	/// marks a certain prototype as Clonable
	/// </summary>
	class IClonable
	{
	private:

	public:
		/// <summary>
		/// creates a copy of the given prototype
		/// </summary>
		/// <param name="x">the x coordinate where to spawn them</param>
		/// <param name="y">the y coordinate where to spawn them</param>
		/// <param name="index">an incremental variable to avoid repeating names</param>
		/// <returns>returns the cloned prototype</returns>
		virtual IClonable* Clone(float x, float y, int index) = 0;
	};

}