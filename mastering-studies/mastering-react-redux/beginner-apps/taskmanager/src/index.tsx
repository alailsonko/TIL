import React from 'react';
import ReactDOM from 'react-dom';
import App from './App';
import { createStore, Store } from 'redux'
import rootReducer from './reducers'
import { Provider } from 'react-redux'

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
  tasks: IRepositoriesState;
}

const store: Store<ApplicationState> = createStore(rootReducer)



ReactDOM.render(
  <React.StrictMode>
    <Provider store={store} >
    <App />
    </Provider>
  </React.StrictMode>,
  document.getElementById('root')
);

