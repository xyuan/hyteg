import os
import time
import math
import random
import re
from influxdb import InfluxDBClient
from git import Repo


def main():
    # try:
    #     write_user_pw = os.environ["INFLUXDB_WRITE_USER"]
    # except KeyError:
    #     import sys
    #     print('Password for the InfluxDB write_user was not set.\n',
    #           'See https://docs.gitlab.com/ee/ci/variables/#secret-variables', file=sys.stderr)
    #     exc_info = sys.exc_info()
    #     raise exc_info[0].with_traceback(exc_info[1], exc_info[2])
    write_user_pw = 'hyteg'

    client = InfluxDBClient('i10grafana.informatik.uni-erlangen.de', 8086,
                            'terraneo', write_user_pw, 'terraneo')

    repo = Repo(search_parent_directories=True)
    commit = repo.head.commit

    with open("P2BenchmarkOutput.txt") as f:
        s = f.read()

    interpolate_constant = re.search( 'interpolate constant: (\d*.\d*)', s )
    interpolate_function = re.search( 'interpolate function: (\d*.\d*)', s )
    assign               = re.search( 'assign:               (\d*.\d*)', s )
    assign_scaled        = re.search( 'assign scaled:        (\d*.\d*)', s )
    apply                = re.search( 'apply:                (\d*.\d*)', s )
    dot                  = re.search( 'dot:                  (\d*.\d*)', s )
    dot_self             = re.search( 'dot self:             (\d*.\d*)', s )

    l = re.search('refinement level: (\d*.\d*)', s)

    json_body = [
        {
            'measurement': 'P2_Benchmark',
            'tags': {
                'host'     : os.uname()[1],
                'project'  : 'terraneo',
                'image'    : os.environ["DOCKER_IMAGE_NAME"],
                'Level'    : int(l.group(1)),
                'commit'  : commit,
            },
            'time': int(time.time()),
            'fields': {'interpolate_constant': float(interpolate_constant.group(1)),
                       'interpolate_function': float(interpolate_function.group(1)),
                       'assign': float(assign.group(1)),
                       'assign_scaled': float(assign_scaled.group(1)),
                       'apply': float(apply.group(1)),
                       'dot': float(dot.group(1)),
                       'dot_self': float(dot_self.group(1)),
                       }
        }
    ]
    client.write_points(json_body, time_precision='s')


if __name__ == "__main__":
    main()
