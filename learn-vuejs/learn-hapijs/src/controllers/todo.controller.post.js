// @flow

interface IReply {
  response(data: any): any,
  code(statusCode: number): any
}

interface IRequest {
  payload: any
}



class CreateTodoController {
  constructor() {}
  
  handle(request: IRequest, reply: IReply): any {

    console.log(request.payload)
    return reply.response(request.payload).code(400)
  }
}

module.exports = CreateTodoController;
