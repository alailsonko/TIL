import React from 'react';
import { StreamChat } from 'stream-chat'
import { Chat } from 'stream-chat-react'
import {
  ChannelContainer,
  ChannelListContainer
} from './components'
import Cookies from 'universal-cookie'

const apiKey = 'fcwccnhrg6f4'

const client = StreamChat.getInstance(apiKey)

function App() {
  return (
    <div className="app_wrapper">
      <Chat client={client} theme="team light">
        <ChannelListContainer />
        <ChannelContainer />
      </Chat>
    </div>
  );
}

export default App;
