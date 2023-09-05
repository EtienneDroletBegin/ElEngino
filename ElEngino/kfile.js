const path = require('path');
const fs = require('fs');
let project = new Project('engine');

 
project.addProvider = function(proj, isRoot=false){
    const sdl2 = true;//process.argv.indexOf("--sdl2") >= 0;
    if(sdl2){
        fs.copyFileSync("./sdl/lib/SDL2.dll", "./Deployment/SDL2.dlls")
        if(!isRoot){
            proj.addDefine("USE_SDL");
            proj.addIncludeDir(path.resolve("./sdl/include"));
        }
        proj.addLib("./sdl/lib/SDL2");
        proj.addLib("./sdl/lib/SDL2main");
    }
    else{
        //Exclude providers
        providers = ["SdlInput","SdlGraphics","SdlAssets"]
        for (let i = 0; i < providers.length; i++) {
            const element = providers[i];
            proj.addExclude(path.resolve("./ElEngino/includes/" + element+'.h'));
            proj.addExclude(path.resolve("./ElEngino/src/" + element+'.cpp'));
            
        }
        }
};
project.kore = false;


project.addDefine("KINC_STATIC_COMPILE");
project.isStaticLib = true;

project.addIncludeDir(path.resolve("./ElEngino/includes"));
project.addFiles('src/**','includes/**');

project.addProvider(project,false);

resolve(project);