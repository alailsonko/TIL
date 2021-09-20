import React from 'react';
import logo from './logo.svg';
import UseStateComponent from './UseStateComponent';
import UseEffectComponent from './UseEffectComponent';
import './App.css';

function App() {
  return (
    <div >
     <h1>useEffect</h1>
     <UseEffectComponent />
     <h1>useState</h1>
     <UseStateComponent />
    </div>
  );
}

export default App;
