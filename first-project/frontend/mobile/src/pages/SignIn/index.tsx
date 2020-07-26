import React from 'react';
import { Image } from 'react-native'

import { Container, Title } from './styles';

import Input from '../../components/Input'
import Button from '../../components/Button'

import logoImg from '../../assets/logo.png'

const SignIn: React.FC = () => {
  return (
  <Container>
    <Image source={logoImg} />
    <Title>Faça seu logon</Title>

    <Input name="email" icon="mail" placeholder="E-mail" />
    <Input name="password" icon="lock" placeholder="password" />

    <Button onPress={() => console.log('hello world')
    }>Entrar</Button>

  </Container>);
}



export default SignIn;
