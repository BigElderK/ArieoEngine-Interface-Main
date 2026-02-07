#pragma once
#include <stdio.h>
#include "interface/archive/archive.h"
using namespace Arieo;
namespace Arieo::Interface::Main
{
    class ITickable
    {
    public:
        virtual void onInitialize() = 0;
        virtual void onTick() = 0;
        virtual void onDeinitialize() = 0;
    };

    class IMainModule
    {
    public:
        
        virtual void loadManifest(const std::string& manifest_path) = 0;
        
        virtual void enqueueTask(Arieo::Core::Coroutine::Task::Tasklet&& task) = 0;
        virtual class Base::Memory::MemoryManager* getMainMemoryManager() = 0;
        virtual Interface::Archive::IArchive* getRootArchive() = 0;

        virtual void registerTickable(ITickable*) = 0;
        virtual void unregisterTickable(ITickable*) = 0;

        virtual void* getAppHandle() = 0;
        
        virtual const std::string& getManifestContent() = 0;
    };
}