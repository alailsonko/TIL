import React from 'react';
import "./App.css"
import axios from 'axios';
import { Link } from 'react-router-dom'
import { AppContext } from './AppContext'

 const TodoList: React.FC = () => {
    const [loading, setLoading] = React.useState(true)
    const {appData, appDispatch} = React.useContext<any>(AppContext)

    React.useEffect(() => {
        axios.get("https://jsonplaceholder.typicode.com/todos").then((resp) => {
            const { data } = resp;
            appDispatch({type: "LOAD_TODOLIST", todoList: data})
            setLoading(false)
        })
    }, [appDispatch, setLoading])

    return (
        <div>
          {loading ? (
  <p>Fetching todos</p>
) : (
  <ul>
    {appData.todoList.slice(0, 15).map((item: any) => {
      const { id, title } = item;
      return (
        <li key={id}>
          <Link to={`/item/${id}`} data-testid={id}>
            {title}
          </Link>
        </li>
      );
    })}
  </ul>
)}
        </div>
    )
}

export default TodoList