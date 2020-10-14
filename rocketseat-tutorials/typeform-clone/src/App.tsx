import React from 'react';

import GlobalStyles from './styles/global'
import { Main, Section, Sticky } from './styles'

import FirstAndSecond  from './components/FirstAndSecond'

function App() {
  React.useEffect(() => {
    window.scrollTo({ top: 0})
  },[])
  return (
    <> 
     <GlobalStyles />   
     <Main style={{height: '1610vh'}} >
       <Section style={{ height: '72.7%' }} >
           <FirstAndSecond />
       </Section>
       <Section style={{ height: '9.7%'}}>
         <Sticky className="third" />
       </Section>
       <Section style={{ height: '10.1%'}}>
         <Sticky className="fourth" />
       </Section>
     </Main>
  
    </>
  );
}

export default App;
