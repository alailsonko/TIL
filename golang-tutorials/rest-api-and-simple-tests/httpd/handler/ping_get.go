package handler

import (
	"net/http"

	"github.com/gin-gonic/gin"
)

// PinGet gives a response
func PingGet() gin.HandlerFunc {
	return func(c *gin.Context) {
		c.JSON(http.StatusOK, map[string]string{
			"hello": "Found me",
		})
	}

}
