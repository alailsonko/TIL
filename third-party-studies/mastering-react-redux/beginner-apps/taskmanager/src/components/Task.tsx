import React from 'react'

const TASK_STATUSES = [
  "Unstarted",
  "In Progress",
  "Completed"
]

const Task: React.FC = (props) => {
    return (
    <div className="task">
      <div className="task-header">
    <div>{props.task.title}</div>
    <select value={props.task.status}> onChange={onStatusChange}
         {TASK_STATUSES.map((status) => (
           <option value={status} key={status}>
             {status}
           </option>
         ))}
    </select>
      </div>
      <hr/>
      <div className="task-body">
        {props.task.description}
      </div>
    </div>
    )
    function onStatusChange (e) {
      props.onStatusChange(props.task, e.target.value)
    }
}

export default Task
