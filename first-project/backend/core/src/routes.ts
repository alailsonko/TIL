import { Request, Response } from 'express'
import createUser from './services/CreateUser'

// string, number, boolean, object, Array
//interfaces

export function helloworld(req: Request, res: Response) {
  const user = createUser({
    name: 'alailson',
    email:'aalailosn@gmail.com',
    password:'heiaheieoa328',
    techs: [
      'nodesjs',
      'reactnvative',
      'reactjs',
      {title: 'js', exp:  100}
    ]
  })
     console.log();

  return res.json({ message: 'hello world' })
}
