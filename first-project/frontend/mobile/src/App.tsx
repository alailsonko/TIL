import 'react-native-gesture-handler'

import React, { useState } from 'react'
import { View, StatusBar } from 'react-native'
import { NavigationContainer } from '@react-navigation/native'
import AppProvider from './hooks'
import Routes from './routes/auth.routes'

import * as Font from 'expo-font';
import { AppLoading } from 'expo';



function App(): React.ReactNode {
    const [dataLoaded, setDataLoaded] = useState(false)



    const fetchFonts = () => {
        return Font.loadAsync({
        'RobotoSlab-Medium': require('../assets/fonts/RobotoSlab-Medium.ttf'),
        'RobotoSlab-Regular': require('../assets/fonts/RobotoSlab-Regular.ttf')
        });
        };

  if(!dataLoaded) {
    return(
      <AppLoading
        startAsync={fetchFonts}
        onFinish={()=>setDataLoaded(true)}
      />
    )
  }

    return (
        <NavigationContainer>
        <StatusBar barStyle="light-content" />
        <AppProvider>
        <View style={{ backgroundColor: '#312e38', flex: 1 }}>
           <Routes />
        </View>
        </AppProvider>


        </NavigationContainer>
    )
}
export default App;
