let project = new Project("Solomon's key");

project.kore = false;

project.addFile("Solomon/**");

project.setDebugDir("Deployment");
project.addIncludeDir("./ElEngino/includes")

project.flatten();

const otherProj = await project.addProject("ElEngino")

otherProj.addProvider(project, true)

resolve(project)