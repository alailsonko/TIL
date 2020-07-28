let _id = 1;
export function uniqueId(): number {
  return _id++;
}

interface Task {
  id: number;
  title: string;
  description: string;
  status: string
}

interface TaskAction {
  type: string;
  payload: object;
}

export function createTask({ title, description }: Task): any {
  return (
    type: 'CREATE_TASK',
    payload: {
      id: uniqueId(),
      title,
      description,
      status: 'Unstarted'
    }
  )
}

export function editTask(id, params = ()) {
  return (
    type: 'EDIT_TASK',
    payload: {
      id,
      params
    }
  )
}
