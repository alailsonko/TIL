import React from 'react'
import Task from './Task'

interface TaskProps {
  id: number;
  title: string;
  description: string;
  status: string;
}


interface Props {
readonly  status: string;
readonly  tasks: TaskProps[];
}

const TaskList: React.FC<Props> = (props) => {
  return (
    <div className="task-list">
      <div className="task-list-title">
        <strong>
          {props.status}
        </strong>
      </div>
      {props.tasks.map((task) => (
        <Task
        key={task.id}
        task={task}
        />
      ))}
    </div>
  )
}

export default TaskList;
