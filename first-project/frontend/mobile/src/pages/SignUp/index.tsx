import React, { useRef } from 'react';
import { useNavigation } from '@react-navigation/native'
import { Form } from '@unform/mobile'
import { FormHandles } from '@unform/core'
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

  BackToSignIn,
  BackToSignInText
} from './styles';

import Input from '../../components/Input'
import Button from '../../components/Button'

import logoImg from '../../assets/logo.png'

const SignUp: React.FC = () => {
  const formRef = useRef<FormHandles>(null)
   const navigation = useNavigation()
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
    <Title>Crie sua conta</Title>
    </View>
    <Form onSubmit={(data) => {console.log(data);
    }} ref={formRef} style={{ width: '100%' }}>
    <Input name="name" icon="user" placeholder="Nome" />
    <Input name="email" icon="mail" placeholder="E-mail" />
    <Input name="password" icon="lock" placeholder="Password" />

    <Button
    onPress={() => formRef.current?.submitForm()}
    >Entrar</Button>
    </Form>

    </Container>
    </ScrollView>
    </KeyboardAvoidingView>
     <BackToSignIn
      onPress={() => navigation.goBack()}>

        <Icon name="arrow-left" size={20} color="#ff9000" />

        <BackToSignInText>Voltar para logon</BackToSignInText>

     </BackToSignIn>

  </>
  )
}



export default SignUp;
