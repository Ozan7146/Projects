
import React from 'react';
import { View, Text } from 'react-native';
import { NavigationContainer } from '@react-navigation/native';
import { createNativeStackNavigator } from '@react-navigation/native-stack';
import HomePage from './Pages/HomePage'
import SecondPage from './Pages/SecondPage'


export default function App() {
  const Stack = createNativeStackNavigator();
  return (
    <NavigationContainer>
      <Stack.Navigator>
        <Stack.Screen name="Home Page" component={HomePage} />
        <Stack.Screen name="SecondPage" component={SecondPage}/>
      </Stack.Navigator>
    </NavigationContainer>
  );
}
