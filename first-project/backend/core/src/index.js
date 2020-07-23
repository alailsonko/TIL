const express = require('express')
const { uuid } = require('uuidv4')

const app = express()

app.use(express.json())

const port = 3333
/**
 * metthods HTTP
 * GET: seek information from backend
 * POST: create one information in the backend
 * PUT/PATCH: change uma information no backend
 * DELETE: delete one information in the backend
 */

 /**
  * types of parameters
  *
  * Query params: filtros e paginação
  * Route params: identify the resources which to delete
  * Request Body: content of body for edit or create one resource
  */

const projects = [];

app.get('/projects', (req, res) => {

  const { title } = req.query;

  const results = title
    ? projects.filter(project => project.title.includes(title))
    : projects;

    return res.json(results)
})

app.post('/projects', (req, res) => {
    const { title, owner } = req.body;
    const project = { id: uuid(), title, owner }

    projects.push(project)

    return res.json(project)
})

app.put('/projects/:id', (req, res) => {

    const { id } = req.params

    const projectIndex = projects.find(project => project.id === id)

    if ( projectIndex < 0){
      return res.status(400).json({ error: 'Project not found'})
    }

    const project = {
      id,
      title,
      owner
    }

    projects[projectIndex] = project;

    return res.json(project)
})

app.delete('/projects/:id', (req, res) => {

  const { id } = req.params

  const projectIndex = projects.find(project => project.id === id)

  if ( projectIndex < 0){
    return res.status(400).json({ error: 'Project not found'})
  }

  projects.splice(projectIndex, 1)

  return res.status(204).send()

})

app.listen(port, () => {
    console.log(`backend started at port ${port}`);
})
