import React from 'react'
import Task from './Task'

const TaskList: React.FC = (props: object) => {
  return (
   <div className="task-list">
     <div className="task-list-title">
  <strong>{props.status}</strong>
     </div>
     {props.tasks.map((task: object) => (
        <Task
         key={task.id}
         task={task}
         onStatusChange={props.onStatusChange}
        />
     ))}
   </div>
  )
}

export default TaskList
