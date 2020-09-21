import { action } from 'typesafe-actions'

import { RepositoryTypes, Repository } from './types'

export const loadRequest = () => action(RepositoryTypes.LOAD_REQUEST)
export const loadSuccess = (data: Repository[]) => action(
  RepositoryTypes.LOAD_SUCCESS,
  { data }
  )
export const loadFailure = () => action(RepositoryTypes.LOAD_FAILURE)
