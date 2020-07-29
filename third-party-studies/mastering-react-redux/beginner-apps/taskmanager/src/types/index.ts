export const CREATE_TASK = 'CREATE_TASK'
export const EDIT_TASK = 'EDIT_TASK'

export interface Task {

  title: string;
  description: string;

}

export interface TaskPayload {
  id: number;
  title: string;
  description: string;
  status: string;
}


interface CreateTaskAction {
  type: typeof CREATE_TASK;
  payload: TaskPayload;
}

interface EditTaskAction {
  type: typeof EDIT_TASK
  payload: Task
}

export type TaskActionTypes = CreateTaskAction
