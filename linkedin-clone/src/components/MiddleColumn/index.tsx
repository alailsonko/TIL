import React from 'react';

import FeedShare from './FeedShare';
import FeedPost from './FeedPost';

import { Container } from './styles';
import LoadFeedPost from '../Shimmer/LoadFeedPost';
import LoadingFeedShare from '../Shimmer/LoadingFeedShare';

const MiddleColumn: React.FC<LoadingProps> = ({ isLoading }) => {
  return (
    <Container className="middle-column">
      {isLoading ? (
         <>
        <LoadingFeedShare />
        <LoadFeedPost/> 
        <LoadFeedPost/> 
        <LoadFeedPost/> 
        <LoadFeedPost/> 
         </>

      ) : (
      <>
      <FeedShare />
      <FeedPost />
      <FeedPost />
      <FeedPost />
      <FeedPost />
     </>
      )}
    </Container>
  );
};

export default MiddleColumn;
