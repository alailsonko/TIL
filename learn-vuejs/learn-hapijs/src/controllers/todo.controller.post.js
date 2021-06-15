// @flow

type TypeReply = {
  response(data: any): any,
  code(statusCode: number): any,
};

type TypeRequest = {
  payload: any,
};

type TypeTODO = {
  task: String,
  date: String,
  reminder: Boolean,
};

class CreateTodoController {
  constructor() {}
  handle(request: TypeRequest, reply: TypeReply): any {
    const data: TypeTODO = request.payload;
    if (!data.task) {
      return reply.response({ error: "task value is missing." }).code(400);
    }
    if (!data.date) {
      return reply.response({ error: "date value is missing." }).code(400);
    }
    if (data.reminder === null) {
      return reply.response({ error: "reminder value is missing." }).code(400);
    }
    return reply.response(request.payload).code(200);
  }
}

module.exports = CreateTodoController;
