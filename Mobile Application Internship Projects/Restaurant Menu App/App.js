import {View, Text} from 'react-native';
import React from 'react';
import { NavigationContainer } from '@react-navigation/native';
import { createNativeStackNavigator } from '@react-navigation/native-stack';
import HomePage from './Pages/HomePage'
import MenuPage from './Pages/MenuPage'
import TotalPage from './Pages/TotalPage'

const Stack = createNativeStackNavigator();
export default function App() {
  return (
    <NavigationContainer>
      <Stack.Navigator initialRouteName="Home">
        <Stack.Screen name="Home" component={HomePage} />
        <Stack.Screen name="Menu" component={MenuPage} />
        <Stack.Screen name="Total" component={TotalPage} />
      </Stack.Navigator>
    </NavigationContainer>
  );
}

