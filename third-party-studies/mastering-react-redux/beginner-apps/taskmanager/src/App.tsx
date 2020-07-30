import React, { Component } from 'react';
import TasksPage from './components/TasksPage'

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
  }
]

class App extends Component {



    render(){
      return (
        <div className="main-content" >
          <TasksPage tasks={mockTasks} />
        </div>
      )
    }


}



export default  App;
