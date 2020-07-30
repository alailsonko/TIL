interface ITask {
  id: number;
  title: string;
  description: string;
  status: string;
}

interface IRepositoriesState {
 readonly tasks: ITask[];
}
const mockTasks = [
  {
    id: 1,
    title: 'Learn Redux',
    description: 'the store, actions, and reducers, oh my',
    status: 'In Progress'
  },
  {
    id: 2,
    title: 'Peace On Earth',
    description: 'No Big Deal',
    status: 'In Progress'
  },
  {
    id: 3,
    title: 'Learn Redux',
    description: 'the store, actions, and reducers, oh my',
    status: 'Completed'
  },
  {
    id: 4,
    title: 'Peace On Earth',
    description: 'No Big Deal',
    status: 'Unstarted'
  },
  {
    id: 5,
    title: 'Learn Redux',
    description: 'the store, actions, and reducers, oh my',
    status: 'In Progress'
  },
  {
    id: 6,
    title: 'Peace On Earth',
    description: 'No Big Deal',
    status: 'In Progress'
  },
  {
    id: 7,
    title: 'Learn Redux',
    description: 'the store, actions, and reducers, oh my',
    status: 'Completed'
  },
  {
    id: 8,
    title: 'Peace On Earth',
    description: 'No Big Deal',
    status: 'Unstarted'
  }
]

const INITIAL_STATE: IRepositoriesState =  {tasks: mockTasks}


export default function tasks(state = INITIAL_STATE, action: string) {
  return state.tasks
}
