import React from 'react';
import logo from './logo.svg';

import './App.css';

interface Props {
  value: any
  onChange: any
  children: any
}

function App() {

  const [search, setSearch] = React.useState('')
  function handleChange(event: any) {
    setSearch(event.target.value)
  }

  return (
    <div>
       <Search value={search} onChange={handleChange}>
         Search:
       </Search>
       <p>Searches for { search ? search : '...' }</p>
    </div>
  );
}

function Search({ value, onChange, children}: Props) {
  return (
    <div>
      <label htmlFor="search">{children}</label>
      <input 
      type="text"
      id="search"
      value={value}
      onChange={onChange}
      />
    </div>
  )
}

export default App;
