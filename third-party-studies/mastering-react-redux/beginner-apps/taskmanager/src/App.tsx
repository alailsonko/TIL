import React, { Component } from 'react';
import TaskPage from './components/TaskPage'
import { connect } from 'react-redux'
import { createTask, editTask } from './actions/index'



class App extends Component<MyProps, MyState> {

  onCreateTask = ({title, description}) => {
     this.props.dispatch(createTask({ title, description }))
  }

  onStatusChange = (id, status) => {
    this.props.dispatch(editTask(id, {status}))
  }

  render() {
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

 const mapStateToProps = (state) => {
  return (
    tasks: state.tasks
  )
}

export default connect(mapStateToProps)(App);
