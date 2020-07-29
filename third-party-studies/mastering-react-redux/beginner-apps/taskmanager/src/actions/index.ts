import { Task, CREATE_TASK, EDIT_TASK, TaskActionTypes, TaskPayload } from '../types'


export function createTask({ title, description }: Task): TaskActionTypes {
  return (
    type: typeof CREATE_TASK,
    payload: {
      id: 1,
      title,
       description,
      status: 'Unstarted'
    }
  )
}

// export function editTask(id, params = ()) {
//   return (
//     type: 'EDIT_TASK',
//     payload: {
//       id,
//       params
//     }
//   )
// }
