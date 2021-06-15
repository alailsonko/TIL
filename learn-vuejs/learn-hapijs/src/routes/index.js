// @flow
const server = require("./../config/server");

server.route([
  {
    method: "GET",
    path: "/",
    handler: (request, h) => {
      console.log(request);
      console.log(h);
      return "Hello World!";
    },
  },
  {
    method: "POST",
    path: "/",
    handler: (request, reply) => {
      console.log(request.payload);
      // console.log(h);
      return reply.response(request.payload).code(200)
    },
  },
]);

module.exports = server;
