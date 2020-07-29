import React, { Component } from 'react';
import TaskPage from './components/TaskPage'
import { connect } from 'react-redux'
import { createTask, editTask } from './actions/index'

interface Task {
  title: string;
  description: string;
}

class App extends Component {

   onCreateTask = ({title, description}: Task) => {
     this.props.dispatch(createTask({ title, description }))
  }

 onStatusChange = (id, status) => {
    this.props.dispatch(editTask(id, {status}))
  }

    render(){
      return (
        <div className="main-content">
            <TaskPage
            tasks={this.props.tasks}
            onCreateTask={this.onCreateTask}
            onStatusChange={this.onStatusChange}
            />
        </div>
      )
    }


}


 const mapStateToProps = (state: any) => {
  return (
    tasks: state.tasks
  )
}

export default connect(mapStateToProps, {createTask, editTask})(App);
