import { all, takeLatest } from 'redux-saga/effects'

import { RepositoryTypes } from './types'
import { load } from './sagas'

export default function* rootSaga() {
  return yield all([
    takeLatest(RepositoryTypes.LOAD_REQUEST, load)
  ])
}
