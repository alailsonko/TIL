import React from 'react';
import {
  Image,
  ScrollView,
  KeyboardAvoidingView,
  Platform,
  View
} from 'react-native'
import Icon from 'react-native-vector-icons/Feather'

import {
  Container,
  Title,
  ForgotPassword,
  ForgotPasswordText,
  CreateAccountButton,
  CreateAccountButtonText
} from './styles';

import Input from '../../components/Input'
import Button from '../../components/Button'

import logoImg from '../../assets/logo.png'

const SignIn: React.FC = () => {
  return (
    <>
    <KeyboardAvoidingView
    style={{ flex: 1}}
    behavior={Platform.OS === 'ios' ? 'padding' : undefined}
    enabled
    >
      <ScrollView keyboardShouldPersistTaps="handled" contentContainerStyle={{ flex: 1 }}>
  <Container>
    <Image source={logoImg} />
    <View>
    <Title>Faça seu logon</Title>
    </View>

    <Input name="email" icon="mail" placeholder="E-mail" />
    <Input name="password" icon="lock" placeholder="password" />

    <Button
    onPress={() => console.log('hello world')}
    >Entrar</Button>

    <ForgotPassword
    onPress={() => console.log('forgot password')}>

      <ForgotPasswordText>Esqueci minha senha</ForgotPasswordText>

    </ForgotPassword>

    </Container>
    </ScrollView>
    </KeyboardAvoidingView>
     <CreateAccountButton
     onPress={() => console.log('create account')}>

        <Icon name="log-in" size={20} color="#ff9000" />

        <CreateAccountButtonText>Criar uma conta</CreateAccountButtonText>

     </CreateAccountButton>

  </>
  )
}



export default SignIn;
