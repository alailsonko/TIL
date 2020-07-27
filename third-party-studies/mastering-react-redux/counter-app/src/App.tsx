import React from 'react';
import { increment, decrement } from './store/actions/counterActions'
import { connect, useDispatch } from 'react-redux'

interface CounterProps {
  counter: number;
}

function App({ counter }: CounterProps) {
  const dispatch = useDispatch()

  return (
    <div>
     <button onClick={() => dispatch(decrement())}>decrement</button>
        <h2>{counter}</h2>
     <button onClick={() => dispatch(increment())}>increment</button>
    </div>
  );
}
const mapStateToProps =(state: any) => {
  return { counter: state.counter }
}
const mapDispatchToProps = { decrement, increment }

export default connect( mapStateToProps, mapDispatchToProps)(App);
