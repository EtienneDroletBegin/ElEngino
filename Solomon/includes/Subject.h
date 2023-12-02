#pragma once
#include "Observer.h"
#include <list>

namespace engino {
	/// <summary>
	/// the bridge between the gameplay and the observer
	/// </summary>
	/// <typeparam name="T">the received value type</typeparam>
	template<typename T>
	class Subject
	{
	public:
		/// <summary>
		/// creates a new trigger to be triggered on runtime
		/// </summary>
		/// <param name="o">the observer to link</param>
		void AddListener(Observer<T>* o)
		{
			m_Observers.push_back(o);
		}
		/// <summary>
		/// removes the added triggers
		/// </summary>
		/// <param name="o">the observer</param>
		void RemoveListener(Observer<T>* o)
		{
			m_Observers.remove(o);
		}
		/// <summary>
		/// Triggers the called action to call upon the observer and send them the data
		/// </summary>
		/// <param name="value">the data to send over</param>
		void Invoke(T& value)
		{
			for (Observer<T>* o : m_Observers)
			{
				o->OnNotify(value);
			}
		}
	private:
		std::list<Observer<T>*> m_Observers;
	};

}
