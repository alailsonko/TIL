import express from 'express'
import ClassesControllers from './controllers/ClassesController'
import ClassesConnections from './controllers/ConnnectionsControllers'

const routes = express()

const classesControllers = new ClassesControllers()
const classesConnections = new ClassesConnections()

routes.post('/classes', classesControllers.create)
routes.get('/classes', classesControllers.index)

routes.post('/connections', classesConnections.create)
routes.get('/connections', classesConnections.index)

export default routes;
