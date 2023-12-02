#pragma once

template<typename T>
/// <summary>
/// allows for delegation of functions without creating extra coupling
/// </summary>
class Observer
{
public:
	virtual ~Observer() = default;
	/// <summary>
	/// the action to execute when an event is triggered
	/// </summary>
	/// <param name="value">values to pass through the observer</param>
	virtual void OnNotify(const T& value) = 0;
};
