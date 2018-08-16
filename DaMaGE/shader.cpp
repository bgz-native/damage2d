#include "shader.h"

namespace dmg { namespace graphics {

    Shader::Shader(const char * vertPath, const char * fragPath)
        : m_VertPath(vertPath), m_FragPath(fragPath)
    {
        m_ShaderID = load();
    }

    Shader::~Shader()
    {

    }

    void Shader::enable() const
    {
        glUseProgram(m_ShaderID);
    }

    void Shader::disable() const
    {
        glUseProgram(0);
    }

    GLuint Shader::load()
    {
        GLuint program = glCreateProgram();

        GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
        GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

        const char* vertSource = read_file(m_VertPath);
        const char* fragSource = read_file(m_FragPath);

        glShaderSource(vertex, 1, &vertSource, NULL);
        glShaderSource(fragment, 1, &fragSource, NULL);

        GLint result;

        glCompileShader(vertex);
        glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);

        if (result == GL_FALSE)
        {
            GLint length;
            glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
            char* log = new char(length);

            glGetShaderInfoLog(vertex, length, &length, log);
            
            printf("Vertex Shader Compile Error\n");

            glDeleteShader(vertex);
            delete[] log;

            return 0;
        }


        glCompileShader(fragment);
        glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);

        if (result == GL_FALSE)
        {
            GLint length;
            glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
            char* log = new char(length);

            glGetShaderInfoLog(fragment, length, &length, log);

            printf("Fragment Shader Compile Error\n");

            glDeleteShader(fragment);
            delete[] log;

            return 0;
        }


        glAttachShader(program, vertex);
        glAttachShader(program, fragment);

        glLinkProgram(program);
        glValidateProgram(program);

        glDeleteShader(vertex);
        glDeleteShader(fragment);

        return program;

    }

} }