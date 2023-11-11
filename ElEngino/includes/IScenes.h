#pragma once
namespace engino {
    class IScenes {
    public:
        virtual ~IScenes() = default;
        virtual void Load() = 0;
        virtual void Update() = 0;

    };

}
