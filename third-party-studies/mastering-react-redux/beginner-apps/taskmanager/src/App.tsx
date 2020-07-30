import React, { Component } from 'react';
import TasksPage from './components/TasksPage'
import { connect } from 'react-redux'

interface ITask {
  id: number;
  title: string;
  description: string;
  status: string;
}

interface IRepositoriesState {
 readonly tasks: ITask[];
}

interface ApplicationState {
 readonly tasks: ITask[];
}

interface OwnProps {

}

type Props = IRepositoriesState & OwnProps

class App extends Component<Props> {


    render(){


      return (
        <div className="main-content" >
          <TasksPage tasks={this.props.tasks} />
        </div>
      )
    }


}

const mapStateToProps = (state: ApplicationState) => {
  return {
     tasks: state.tasks
  }
}


export default connect(mapStateToProps)(App);
