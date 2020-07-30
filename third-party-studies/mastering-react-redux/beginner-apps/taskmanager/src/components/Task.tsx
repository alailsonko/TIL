import React from 'react'

interface Props {
  id: number;
  title: string;
  description: string;
  status: string;
}

interface TaskProps {
  task: Props;
}

const Task: React.FC<TaskProps> = ({ task }) => {
  return (
     <div className="task">
      <div className="task-header">
           <div>{task.title}</div>
      </div>
      <hr/>
      <div className="task-body">
        {task.description}
      </div>
     </div>
  )
}

export default Task;
