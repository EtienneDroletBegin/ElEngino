#pragma once
namespace engino {
    class IScenes {
    public:
        IScenes() = default;
        virtual ~IScenes() = default;
        /// <summary>
        /// Loads all of the essentials into the scene
        /// </summary>
        virtual void Load() = 0;
        virtual void Update(float dt) = 0;

    };

}
