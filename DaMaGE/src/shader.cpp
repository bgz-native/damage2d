#include "shader.h"

namespace dmg { namespace graphics {

    Shader::Shader(const char* vertPath, 
                   const char* fragPath) :
                   m_VertPath(vertPath) , 
                   m_FragPath(fragPath)
    {
        m_ShaderID = load();
    }

    Shader::~Shader()
    {
        glDeleteProgram(m_ShaderID);
    }

    void Shader::enable() const
    {
        glUseProgram(m_ShaderID);
    }

    void Shader::disable() const
    {
        glUseProgram(0);
    }

    void Shader::setUniform1f(const GLchar* name, float value)
    {
        glUniform1f(getUniformLocation(name), value);
    }

    void Shader::setUniform1i(const GLchar* name, int value)
    {
        glUniform1f(getUniformLocation(name), value);
    }

    void Shader::setUniform2f(const GLchar* name, const DMG_VEC2& vector)
    {
        glUniform2f(getUniformLocation(name), vector.x, vector.y);
    }

    void Shader::setUniform3f(const GLchar* name, const DMG_VEC3& vector)
    {
        glUniform3f(getUniformLocation(name), vector.x, vector.y, vector.z);
    }

    void Shader::setUniform4f(const GLchar * name, const DMG_VEC4 & vector)
    {
        glUniform4f(getUniformLocation(name), vector.x, vector.y, vector.z, vector.a);
    }

    void Shader::setUniformMat4(const GLchar* name, const DMG_MAT4& mat4)
    {
        glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, mat4.getElements());
    }

    GLint Shader::getUniformLocation(const GLchar* name)
    {
        return glGetUniformLocation(m_ShaderID, name);
    }

    GLuint Shader::load()
    {
        GLuint program = glCreateProgram();

        GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
        GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

        const char* vertSource = util::read_file(m_VertPath);
        const char* fragSource = util::read_file(m_FragPath);

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
            
            printf("Vertex Shader Compile Error:\n %s\n", log);

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

            printf("Fragment Shader Compile Error:\n %s\n", log);

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