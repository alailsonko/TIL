const prodConfig = {
    port: process.env.PORT || 3333,
    database: 'mongodb://localhost/express',
    secrets: {
        API_KEY: process.env.API_KEY
    }
}

export default prodConfig