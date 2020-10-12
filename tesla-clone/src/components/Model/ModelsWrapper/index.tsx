import React, { useRef, useState, useCallback } from 'react';

import { CarModel } from '../ModelsContext'
import ModelsContext from '../ModelsContext'

import ModelOverlay from '../ModelOverlay'

import { 
  Container,
  OverlaysRoot
} from './styles';

const ModelsWrapper: React.FC = ({ children }) => {
  
  const wrapperRef = useRef<HTMLDivElement>(null)

  const [registeredModels, setRegisteredModels] = useState<CarModel[]>([])

  const registerModel = useCallback(( model: CarModel ): void => {
      setRegisteredModels(state => [...state, model])
  }, [])

const unregisterModel = useCallback(( modelName: string ): void => {
       setRegisteredModels(state => state.filter(model => model.modelName !== modelName))
}, [])

const getModelByName = useCallback(( modelName: string) =>{
    return registeredModels.find(item => item.modelName === modelName) || null
}, [registeredModels])

  return (
    <ModelsContext.Provider 
      value={{
        wrapperRef,
        registeredModels,
        registerModel,
        unregisterModel,
        getModelByName
      }}
    >
      <Container ref={wrapperRef} >
        <OverlaysRoot>
           {registeredModels.map(item => (
             <ModelOverlay model={item} key={item.modelName}>
               {item.overlayNode}
             </ModelOverlay>
           ))}
        </OverlaysRoot>
      {children}
    </Container> 
    </ModelsContext.Provider>

  );
};

export default ModelsWrapper;
