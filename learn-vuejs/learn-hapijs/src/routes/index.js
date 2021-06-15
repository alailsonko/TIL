// @flow
const server = require("./../config/server");
const CreateTodoController = require("./../controllers/todo.controller.post");

const createTodoController = new CreateTodoController()

server.route([
  {
    method: "GET",
    path: "/todos",
    handler: (request, h) => {
      console.log(request);
      console.log(h);
      return "Hello World!";
    },
  },
  {
    method: "POST",
    path: "/todos",
    handler: (request, reply) => createTodoController.handle(request, reply),
  },
]);

module.exports = server;
