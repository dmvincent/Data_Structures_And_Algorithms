pipeline {
    agent {
        node {
            label 'docker-agent-pytest'
        }
    }
    triggers {
        pollSCM 'H/5 * * * *'
    }
    stages {
        stage('Checkout') {
            steps {
                checkout scmGit(branches: [[name: '*/main']], extensions: [], userRemoteConfigs: [[url: 'https://github.com/dmvincent/Data_Structures_And_Algorithms']])
            }
        }
        stage('Build') {
            steps {
                sh 'python3 Hashing/Maximum_Number_Of_Balloons/py/solution.py'
            }
        }
        stage('Test') {
            steps {
                sh 'pytest -v Hashing/Maximum_Number_Of_Balloons/py/pytest_testing/test_solution.py'
                sh 'pytest -v Hashing/Contiguous_Array -m hashing'
            }
        }
    }
}
