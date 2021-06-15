// @flow

type IReply = {
  response(data: any): any;
  code(statusCode: number): any;
}

type IRequest = {
  payload: any;
}

class CreateTodoController {
  constructor() {}
  handle(request: IRequest, reply: IReply): any {
    return reply.response(request.payload).code(400);
  }
}

module.exports = CreateTodoController;
