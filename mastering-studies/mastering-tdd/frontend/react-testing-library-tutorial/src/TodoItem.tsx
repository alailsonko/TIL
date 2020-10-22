import React from 'react'
import { useParams } from 'react-router-dom'

import './App.css'

const TodoItem: React.FC = () => {
    const { id } = useParams()

    return (
        <div className="single-todo-item">
            
        </div>
    )
}

export default TodoItem